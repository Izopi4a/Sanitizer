
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
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Booleans) {

	ZEPHIR_REGISTER_CLASS_EX(Sanitizer\\Sanitizers, Booleans, sanitizer, sanitizers_booleans, sanitizer_sanitizer_ce, sanitizer_sanitizers_booleans_method_entry, 0);

	zend_declare_property_bool(sanitizer_sanitizers_booleans_ce, SL("val"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(sanitizer_sanitizers_booleans_ce TSRMLS_CC, 1, sanitizer_sanitizerinterface_ce);
	return SUCCESS;

}

/**
 * returns filtered value
 *
 * @return bool
 */
PHP_METHOD(Sanitizer_Sanitizers_Booleans, getValue) {

	zval v, b$$7, _2$$7, _3$$7;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&b$$7);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&v, this_ptr, "getrawvalue", NULL, 0);
	zephir_check_call_status();
	if ((Z_TYPE_P(&v) == IS_TRUE || Z_TYPE_P(&v) == IS_FALSE)) {
		RETURN_CCTOR(&v);
	}
	if (1 == zephir_is_numeric(&v)) {
		_0$$4 = zephir_get_intval(&v);
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_LONG(&v, _0$$4);
		if (ZEPHIR_IS_LONG_IDENTICAL(&v, 1)) {
			RETURN_MM_BOOL(1);
		} else if (ZEPHIR_IS_LONG_IDENTICAL(&v, 0)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_1, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(&v) == IS_STRING) {
		ZVAL_LONG(&_2$$7, 258);
		ZVAL_LONG(&_3$$7, 134217728);
		ZEPHIR_CALL_FUNCTION(&b$$7, "filter_var", NULL, 11, &v, &_2$$7, &_3$$7);
		zephir_check_call_status();
		if (Z_TYPE_P(&b$$7) == IS_NULL) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_1, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_update_property_zval(this_ptr, SL("val"), &b$$7);
	}
	RETURN_MM_MEMBER(getThis(), "val");

}

/**
 * returns default value for this object
 *
 * @return bool
 */
PHP_METHOD(Sanitizer_Sanitizers_Booleans, getDefaultValue) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

