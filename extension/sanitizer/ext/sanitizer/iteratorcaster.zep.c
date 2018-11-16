
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * class that helps you sanitize your user inputs
 *
 * Class Caster
 * @package Sanitizer
 */
ZEPHIR_INIT_CLASS(Sanitizer_IteratorCaster) {

	ZEPHIR_REGISTER_CLASS(Sanitizer, IteratorCaster, sanitizer, iteratorcaster, sanitizer_iteratorcaster_method_entry, 0);

	zend_declare_property_null(sanitizer_iteratorcaster_ce, SL("sanitizers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sanitizer_iteratorcaster_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	sanitizer_iteratorcaster_ce->create_object = zephir_init_properties_Sanitizer_IteratorCaster;

	zend_class_implements(sanitizer_iteratorcaster_ce TSRMLS_CC, 1, sanitizer_casterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Sanitizer_IteratorCaster, __construct) {

	zend_bool _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval items;
	zval *data, data_sub, *items_param = NULL, _1, item$$4, *_2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&item$$4);
	ZVAL_UNDEF(&items);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &items_param);

	if (!items_param) {
		ZEPHIR_INIT_VAR(&items);
		array_init(&items);
	} else {
		zephir_get_arrval(&items, items_param);
	}


	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_iterable", NULL, 1, data);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "data must be array or other iterable", "sanitizer/IteratorCaster.zep", 18);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("data"), data);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&items, "")) {
		zephir_is_iterable(&items, 0, "sanitizer/IteratorCaster.zep", 28);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&items), _2$$4)
		{
			ZEPHIR_INIT_NVAR(&item$$4);
			ZVAL_COPY(&item$$4, _2$$4);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_3, 0, &item$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item$$4);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * adds sanitizer to the object
 * sanitizers are the one returning values from data source
 *
 * @param SanitizerInterface $sanitizer
 *
 * @return $this
 */
PHP_METHOD(Sanitizer_IteratorCaster, add) {

	zval *sanitizer, sanitizer_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sanitizer_sub);

	zephir_fetch_params(0, 1, 0, &sanitizer);



	zephir_update_property_array_append(this_ptr, SL("sanitizers"), sanitizer TSRMLS_CC);
	RETURN_THISW();

}

/**
 * returns sanitized data
 *
 * @return array
 */
PHP_METHOD(Sanitizer_IteratorCaster, getData) {

	zval data, sanitizer, _0, *_1, varName$$3, _2$$3, _4$$3, _5$$3, _6$$3, _3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&sanitizer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&varName$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_read_property(&_0, this_ptr, SL("sanitizers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "sanitizer/IteratorCaster.zep", 72);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&sanitizer);
		ZVAL_COPY(&sanitizer, _1);
		ZEPHIR_CALL_METHOD(&varName$$3, &sanitizer, "getvariablename", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_2$$3, &varName$$3) == 0) {
			ZEPHIR_CALL_METHOD(&_3$$4, &sanitizer, "getdefaultvalue", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&data, &varName$$3, &_3$$4, PH_COPY | PH_SEPARATE);
			continue;
		}
		zephir_read_property(&_4$$3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$3, &_4$$3, &varName$$3, PH_NOISY | PH_READONLY, "sanitizer/IteratorCaster.zep", 68 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &sanitizer, "setrawvalue", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$3, &sanitizer, "getvalue", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&data, &varName$$3, &_6$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&sanitizer);
	RETURN_CCTOR(&data);

}

zend_object *zephir_init_properties_Sanitizer_IteratorCaster(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("data"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("sanitizers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("sanitizers"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

