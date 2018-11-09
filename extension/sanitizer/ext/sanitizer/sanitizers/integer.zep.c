
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Integer) {

	ZEPHIR_REGISTER_CLASS_EX(Sanitizer\\Sanitizers, Integer, sanitizer, sanitizers_integer, sanitizer_sanitizer_ce, sanitizer_sanitizers_integer_method_entry, 0);

	zend_declare_property_null(sanitizer_sanitizers_integer_ce, SL("min"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sanitizer_sanitizers_integer_ce, SL("max"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(sanitizer_sanitizers_integer_ce, SL("val"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(sanitizer_sanitizers_integer_ce TSRMLS_CC, 1, sanitizer_sanitizerinterface_ce);
	return SUCCESS;

}

/**
 * returns filtered value
 *
 * @return int|null
 */
PHP_METHOD(Sanitizer_Sanitizers_Integer, getValue) {

	zend_bool _3, _6;
	zval v, _1, _2, _4, _5, _7;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&v, this_ptr, "getrawvalue", NULL, 0);
	zephir_check_call_status();
	if (0 == zephir_is_numeric(&v)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_0, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, zephir_get_intval(&v));
	zephir_update_property_zval(this_ptr, SL("val"), &_1);
	zephir_read_property(&_1, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_1, 0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_0, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_2, this_ptr, SL("min"), PH_NOISY_CC | PH_READONLY);
	_3 = Z_TYPE_P(&_2) != IS_NULL;
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "checkmin", NULL, 0);
		zephir_check_call_status();
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	if (_3) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_0, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_5, this_ptr, SL("max"), PH_NOISY_CC | PH_READONLY);
	_6 = Z_TYPE_P(&_5) != IS_NULL;
	if (_6) {
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "checkmax", NULL, 0);
		zephir_check_call_status();
		_6 = ZEPHIR_IS_FALSE_IDENTICAL(&_7);
	}
	if (_6) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_0, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "val");

}

/**
 * validates if number is > than set minimum
 *
 * @return bool
 */
PHP_METHOD(Sanitizer_Sanitizers_Integer, checkMin) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("min"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_LE(&_0, &_1));

}

/**
 * validates if value is < than set maximum
 *
 * @return bool
 */
PHP_METHOD(Sanitizer_Sanitizers_Integer, checkMax) {

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
PHP_METHOD(Sanitizer_Sanitizers_Integer, setMinimum) {

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
PHP_METHOD(Sanitizer_Sanitizers_Integer, setMaximum) {

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
 * @return int|null
 */
PHP_METHOD(Sanitizer_Sanitizers_Integer, getDefaultValue) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("nullAsDefault"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_NULL();
	}
	RETURN_LONG(0);

}

