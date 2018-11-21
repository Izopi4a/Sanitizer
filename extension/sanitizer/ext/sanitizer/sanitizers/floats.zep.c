
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/math.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Floats) {

	ZEPHIR_REGISTER_CLASS_EX(Sanitizer\\Sanitizers, Floats, sanitizer, sanitizers_floats, sanitizer_sanitizer_ce, sanitizer_sanitizers_floats_method_entry, 0);

	zend_declare_property_null(sanitizer_sanitizers_floats_ce, SL("min"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sanitizer_sanitizers_floats_ce, SL("max"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_double(sanitizer_sanitizers_floats_ce, SL("val"), 0.00, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(sanitizer_sanitizers_floats_ce, SL("maxDecimals"), 2, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(sanitizer_sanitizers_floats_ce TSRMLS_CC, 1, sanitizer_sanitizerinterface_ce);
	zend_class_implements(sanitizer_sanitizers_floats_ce TSRMLS_CC, 1, sanitizer_sizeinterface_ce);
	return SUCCESS;

}

/**
 * returns filtered value
 *
 * @return float|null
 */
PHP_METHOD(Sanitizer_Sanitizers_Floats, getValue) {

	zend_bool _9, _12;
	zval v, _4, _5, _6, _7, _8, _10, _11, _13, _0$$3, _1$$3, _2$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&v, this_ptr, "getrawvalue", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&v) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, ",");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, ".");
		zephir_fast_str_replace(&_0$$3, &_1$$3, &_2$$3, &v TSRMLS_CC);
		ZEPHIR_CPY_WRT(&v, &_0$$3);
	}
	if (0 == zephir_is_numeric(&v)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_3, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CALL_FUNCTION(&_5, "floatval", NULL, 12, &v);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("maxDecimals"), PH_NOISY_CC | PH_READONLY);
	zephir_round(&_4, &_5, &_6, NULL TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("val"), &_4);
	ZEPHIR_OBS_VAR(&_7);
	zephir_read_property(&_7, this_ptr, SL("val"), PH_NOISY_CC);
	if (zephir_get_intval(&_7) == 0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_3, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_8, this_ptr, SL("min"), PH_NOISY_CC | PH_READONLY);
	_9 = Z_TYPE_P(&_8) != IS_NULL;
	if (_9) {
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "checkmin", NULL, 0);
		zephir_check_call_status();
		_9 = ZEPHIR_IS_FALSE_IDENTICAL(&_10);
	}
	if (_9) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_3, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_11, this_ptr, SL("max"), PH_NOISY_CC | PH_READONLY);
	_12 = Z_TYPE_P(&_11) != IS_NULL;
	if (_12) {
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "checkmax", NULL, 0);
		zephir_check_call_status();
		_12 = ZEPHIR_IS_FALSE_IDENTICAL(&_13);
	}
	if (_12) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_3, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "val");

}

/**
 * @param int max
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Floats, setMaxDecimals) {

	zval *max_param = NULL, _0;
	zend_long max;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &max_param);

	max = zephir_get_intval(max_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, max);
	zephir_update_property_zval(this_ptr, SL("maxDecimals"), &_0);
	RETURN_THISW();

}

/**
 * validates if number is > than set minimum
 *
 * @return bool
 */
PHP_METHOD(Sanitizer_Sanitizers_Floats, checkMin) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("min"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_LE(&_0, &_1));

}

/**
 * validates if value is < than set maximum
 *
 * @return bool
 */
PHP_METHOD(Sanitizer_Sanitizers_Floats, checkMax) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("max"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_GE(&_0, &_1));

}

/**
 * updates object to set required minimum
 *
 * @param int min
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Floats, setMinimum) {

	zval *min_param = NULL, _0;
	zend_long min;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &min_param);

	min = zephir_get_intval(min_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, min);
	zephir_update_property_zval(this_ptr, SL("min"), &_0);
	RETURN_THISW();

}

/**
 * updates object to set required maximum
 *
 * @param int max
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Floats, setMaximum) {

	zval *max_param = NULL, _0;
	zend_long max;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &max_param);

	max = zephir_get_intval(max_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, max);
	zephir_update_property_zval(this_ptr, SL("max"), &_0);
	RETURN_THISW();

}

/**
 * returns default value for this object
 *
 * @return float|null
 */
PHP_METHOD(Sanitizer_Sanitizers_Floats, getDefaultValue) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("nullAsDefault"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_NULL();
	}
	RETURN_DOUBLE(0.00);

}

