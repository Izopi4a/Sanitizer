
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
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Password) {

	ZEPHIR_REGISTER_CLASS_EX(Sanitizer\\Sanitizers, Password, sanitizer, sanitizers_password, sanitizer_sanitizer_ce, sanitizer_sanitizers_password_method_entry, 0);

	zend_declare_property_null(sanitizer_sanitizers_password_ce, SL("minLength"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sanitizer_sanitizers_password_ce, SL("maxLength"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(sanitizer_sanitizers_password_ce, SL("val"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(sanitizer_sanitizers_password_ce TSRMLS_CC, 1, sanitizer_sanitizerinterface_ce);
	zend_class_implements(sanitizer_sanitizers_password_ce TSRMLS_CC, 1, sanitizer_lengthinterface_ce);
	return SUCCESS;

}

/**
 * returns filtered value
 *
 * @return null|string
 */
PHP_METHOD(Sanitizer_Sanitizers_Password, getValue) {

	zend_bool _0, _1, _4, _9, _12;
	zval v, _3, _5, _6, _7, _8, _10, _11, _13;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&v, this_ptr, "getrawvalue", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&v) == IS_NULL;
	if (!(_0)) {
		_0 = (Z_TYPE_P(&v) == IS_TRUE || Z_TYPE_P(&v) == IS_FALSE);
	}
	_1 = _0;
	if (!(_1)) {
		_1 = Z_TYPE_P(&v) == IS_ARRAY;
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_2, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_update_property_zval(this_ptr, SL("val"), &v);
	zephir_read_property(&_3, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	_4 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "");
	if (!(_4)) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_read_property(&_6, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_trim(&_5, &_6, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		_4 = ZEPHIR_IS_STRING_IDENTICAL(&_5, "");
	}
	if (_4) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_2, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_7, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_7, "")) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_2, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_8, this_ptr, SL("minLength"), PH_NOISY_CC | PH_READONLY);
	_9 = Z_TYPE_P(&_8) != IS_NULL;
	if (_9) {
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "checkminlength", NULL, 0);
		zephir_check_call_status();
		_9 = ZEPHIR_IS_FALSE_IDENTICAL(&_10);
	}
	if (_9) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_2, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_11, this_ptr, SL("maxLength"), PH_NOISY_CC | PH_READONLY);
	_12 = Z_TYPE_P(&_11) != IS_NULL;
	if (_12) {
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "checkmaxlength", NULL, 0);
		zephir_check_call_status();
		_12 = ZEPHIR_IS_FALSE_IDENTICAL(&_13);
	}
	if (_12) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_2, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "val");

}

/**
 * validates if string length is more than the one set
 *
 * @return bool
 */
PHP_METHOD(Sanitizer_Sanitizers_Password, checkMinLength) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("minLength"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_LE_LONG(&_0, zephir_fast_strlen_ev(&_1)));

}

/**
 * validates if string length is less than the one set
 *
 * @return bool
 */
PHP_METHOD(Sanitizer_Sanitizers_Password, checkMaxLength) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("maxLength"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_GE_LONG(&_0, zephir_fast_strlen_ev(&_1)));

}

/**
 * updates object property for min length
 *
 * @param int min
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Password, setMinLength) {

	zval *min_param = NULL, _0;
	zend_long min;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &min_param);

	min = zephir_get_intval(min_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, min);
	zephir_update_property_zval(this_ptr, SL("minLength"), &_0);
	RETURN_THISW();

}

/**
 * updates object property for max length
 *
 * @param int max
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Password, setMaxLength) {

	zval *max_param = NULL, _0;
	zend_long max;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &max_param);

	max = zephir_get_intval(max_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, max);
	zephir_update_property_zval(this_ptr, SL("maxLength"), &_0);
	RETURN_THISW();

}

/**
 * returns default value for this object
 *
 * @return null|string
 */
PHP_METHOD(Sanitizer_Sanitizers_Password, getDefaultValue) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("nullAsDefault"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_NULL();
	}
	RETURN_STRING("");

}

