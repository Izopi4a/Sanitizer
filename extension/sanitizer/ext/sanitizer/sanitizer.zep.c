
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Sanitizer_Sanitizer) {

	ZEPHIR_REGISTER_CLASS(Sanitizer, Sanitizer, sanitizer, sanitizer, sanitizer_sanitizer_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/** @var bool */
	zend_declare_property_bool(sanitizer_sanitizer_ce, SL("nullAsDefault"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sanitizer_sanitizer_ce, SL("rawValue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/** @var string  */
	zend_declare_property_string(sanitizer_sanitizer_ce, SL("variableName"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sanitizer constructor.
 *
 * @param null|string variableName
 */
PHP_METHOD(Sanitizer_Sanitizer, __construct) {

	zval *variableName_param = NULL;
	zval variableName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variableName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &variableName_param);

	if (!variableName_param) {
		ZEPHIR_INIT_VAR(&variableName);
		ZVAL_STRING(&variableName, "");
	} else {
		zephir_get_strval(&variableName, variableName_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&variableName, "")) {
		RETURN_MM_NULL();
	}
	zephir_update_property_zval(this_ptr, SL("variableName"), &variableName);
	ZEPHIR_MM_RESTORE();

}

/**
 * variable name / key name in data array
 *
 * @return string
 */
PHP_METHOD(Sanitizer_Sanitizer, getVariableName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "variableName");

}

/**
 * when defaultValue is returned if enabled
 *
 * @param bool state
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizer, setNullAsDefault) {

	zval *state_param = NULL, __$true, __$false;
	zend_bool state;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &state_param);

	state = zephir_get_boolval(state_param);


	if (state) {
		zephir_update_property_zval(this_ptr, SL("nullAsDefault"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("nullAsDefault"), &__$false);
	}
	RETURN_THISW();

}

/**
 * assigns value to be sanitized to the object
 *
 * @param value
 */
PHP_METHOD(Sanitizer_Sanitizer, setRawValue) {

	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_zval(this_ptr, SL("rawValue"), value);

}

/**
 * returns non-serialized value of the object
 *
 * @return mixed
 */
PHP_METHOD(Sanitizer_Sanitizer, getRawValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "rawValue");

}

