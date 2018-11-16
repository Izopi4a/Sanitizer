
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_ArrayInteger) {

	ZEPHIR_REGISTER_CLASS_EX(Sanitizer\\Sanitizers, ArrayInteger, sanitizer, sanitizers_arrayinteger, sanitizer_sanitizer_ce, sanitizer_sanitizers_arrayinteger_method_entry, 0);

	zend_declare_property_null(sanitizer_sanitizers_arrayinteger_ce, SL("min"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sanitizer_sanitizers_arrayinteger_ce, SL("max"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(sanitizer_sanitizers_arrayinteger_ce, SL("val"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/** @var int  */
	zend_declare_property_long(sanitizer_sanitizers_arrayinteger_ce, SL("maxItems"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);

	sanitizer_sanitizers_arrayinteger_ce->create_object = zephir_init_properties_Sanitizer_Sanitizers_ArrayInteger;

	zend_class_implements(sanitizer_sanitizers_arrayinteger_ce TSRMLS_CC, 1, sanitizer_sanitizerinterface_ce);
	return SUCCESS;

}

/**
 * returns filtered value
 *
 * @return array
 */
PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, getValue) {

	zend_bool _3;
	zval v, integers, _0, _1, _2, value$$4, _6$$4, _12$$4, newValues$$4, _10$$6, _13$$7;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_9 = NULL, *_11 = NULL, *_14 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, max = 0, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&integers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&value$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&newValues$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&v, this_ptr, "getrawvalue", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&v) != IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_0, "array_values", NULL, 2, &v);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&v, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, SL("maxItems"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_2, -1)) {
		ZEPHIR_OBS_NVAR(&_1);
		zephir_read_property(&_1, this_ptr, SL("maxItems"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, zephir_fast_count_int(&v TSRMLS_CC));
	}
	max = zephir_get_numberval(&_1);
	_5 = (max - 1);
	_4 = 0;
	_3 = 0;
	if (_4 <= _5) {
		while (1) {
			if (_3) {
				_4++;
				if (!(_4 <= _5)) {
					break;
				}
			} else {
				_3 = 1;
			}
			i = _4;
			if (0 == zephir_array_isset_long(&v, i)) {
				break;
			}
			ZEPHIR_OBS_NVAR(&value$$4);
			zephir_array_fetch_long(&value$$4, &v, i, PH_NOISY, "sanitizer/Sanitizers/ArrayInteger.zep", 44 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&integers);
			object_init_ex(&integers, sanitizer_sanitizers_integer_ce);
			ZVAL_NULL(&_6$$4);
			ZEPHIR_CALL_METHOD(NULL, &integers, "__construct", &_7, 3, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &integers, "setrawvalue", &_8, 4, &value$$4);
			zephir_check_call_status();
			ZVAL_BOOL(&_6$$4, 1);
			ZEPHIR_CALL_METHOD(NULL, &integers, "setnullasdefault", &_9, 5, &_6$$4);
			zephir_check_call_status();
			zephir_read_property(&_6$$4, this_ptr, SL("max"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_6$$4) != IS_NULL) {
				zephir_read_property(&_10$$6, this_ptr, SL("max"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &integers, "setmaximum", &_11, 6, &_10$$6);
				zephir_check_call_status();
			}
			zephir_read_property(&_12$$4, this_ptr, SL("min"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_12$$4) != IS_NULL) {
				zephir_read_property(&_13$$7, this_ptr, SL("min"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &integers, "setminimum", &_14, 7, &_13$$7);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&newValues$$4, &integers, "getvalue", &_15, 8);
			zephir_check_call_status();
			if (Z_TYPE_P(&newValues$$4) != IS_NULL) {
				zephir_update_property_array_append(this_ptr, SL("val"), &newValues$$4 TSRMLS_CC);
			}
		}
	}
	RETURN_MM_MEMBER(getThis(), "val");

}

/**
 * set maximum number of elements inside the array
 *
 * THIS DOES NOT GUARANTEE THE ARRAY WILL HAVE {amount} of ITEMS
 *
 * @param int maxItems
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, setMaxItems) {

	zval *maxItems_param = NULL, _0;
	zend_long maxItems;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &maxItems_param);

	if (UNEXPECTED(Z_TYPE_P(maxItems_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'maxItems' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	maxItems = Z_LVAL_P(maxItems_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, maxItems);
	zephir_update_property_zval(this_ptr, SL("maxItems"), &_0);
	RETURN_THISW();

}

/**
 * updates object to set required minimum
 *
 * @param int min
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, setMinimum) {

	zval *min_param = NULL, _0;
	zend_long min;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &min_param);

	if (UNEXPECTED(Z_TYPE_P(min_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'min' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	min = Z_LVAL_P(min_param);


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
PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, setMaximum) {

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
 * @return array|null
 */
PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, getDefaultValue) {

	zval *this_ptr = getThis();


	array_init(return_value);
	return;

}

zend_object *zephir_init_properties_Sanitizer_Sanitizers_ArrayInteger(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("val"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

