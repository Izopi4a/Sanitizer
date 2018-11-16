
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Emails) {

	ZEPHIR_REGISTER_CLASS_EX(Sanitizer\\Sanitizers, Emails, sanitizer, sanitizers_emails, sanitizer_sanitizer_ce, sanitizer_sanitizers_emails_method_entry, 0);

	/** @var string  */
	zend_declare_property_string(sanitizer_sanitizers_emails_ce, SL("val"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(sanitizer_sanitizers_emails_ce TSRMLS_CC, 1, sanitizer_sanitizerinterface_ce);
	return SUCCESS;

}

/**
 * returns filtered value
 *
 * @return null|string
 */
PHP_METHOD(Sanitizer_Sanitizers_Emails, getValue) {

	zval strings, _0, _1, _2, _4, _5, _6;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strings);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&strings);
	object_init_ex(&strings, sanitizer_sanitizers_strings_ce);
	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, &strings, "__construct", NULL, 2, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getrawvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &strings, "setrawvalue", NULL, 3, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &strings, "getvalue", NULL, 9);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("val"), &_2);
	zephir_read_property(&_0, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "")) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_3, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_4, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 274);
	ZEPHIR_CALL_FUNCTION(&_6, "filter_var", NULL, 8, &_4, &_5);
	zephir_check_call_status();
	if (!zephir_is_true(&_6)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_3, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "val");

}

/**
 * returns default value for this object
 *
 * @return null|string
 */
PHP_METHOD(Sanitizer_Sanitizers_Emails, getDefaultValue) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("nullAsDefault"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_NULL();
	}
	RETURN_STRING("");

}

