
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Date) {

	ZEPHIR_REGISTER_CLASS_EX(Sanitizer\\Sanitizers, Date, sanitizer, sanitizers_date, sanitizer_sanitizer_ce, sanitizer_sanitizers_date_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(sanitizer_sanitizers_date_ce, SL("val"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(sanitizer_sanitizers_date_ce, SL("readFormat"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(sanitizer_sanitizers_date_ce, SL("returnFormat"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \DateTimeZone
	 */
	zend_declare_property_null(sanitizer_sanitizers_date_ce, SL("timeZone"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(sanitizer_sanitizers_date_ce, SL("returnAsObject"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(sanitizer_sanitizers_date_ce, SL("returnAsTimestamp"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(sanitizer_sanitizers_date_ce, SL("manualTime"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_long(sanitizer_sanitizers_date_ce, SL("hour"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_long(sanitizer_sanitizers_date_ce, SL("minute"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_long(sanitizer_sanitizers_date_ce, SL("second"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * returns formatted value
 *
 * @return \DateTime|int|string|null
 * @throws \Exception
 */
PHP_METHOD(Sanitizer_Sanitizers_Date, getValue) {

	zval strings, _0, _1, v, _3, _4, _6, _7, _5$$6;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strings);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&strings);
	object_init_ex(&strings, sanitizer_sanitizers_strings_ce);
	ZEPHIR_CALL_METHOD(NULL, &strings, "__construct", NULL, 2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getrawvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &strings, "setrawvalue", NULL, 3, &_0);
	zephir_check_call_status();
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, &strings, "setnullasdefault", NULL, 4, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&v, &strings, "getvalue", NULL, 10);
	zephir_check_call_status();
	if (Z_TYPE_P(&v) == IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_2, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "readdate", NULL, 0, &v);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&v, &_3);
	if (Z_TYPE_P(&v) == IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", &_2, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_update_property_zval(this_ptr, SL("val"), &v);
	zephir_read_property(&_1, this_ptr, SL("returnAsObject"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		RETURN_MM_MEMBER(getThis(), "val");
	}
	zephir_read_property(&_4, this_ptr, SL("returnAsTimestamp"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_4)) {
		zephir_read_property(&_5$$6, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_5$$6, "gettimestamp", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_6, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, SL("returnFormat"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_6, "format", NULL, 0, &_7);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * If Date is valid, timestamp will be returned
 *
 * @param bool state
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Date, setReturnAsTimeStamp) {

	zval *state_param = NULL, __$true, __$false;
	zend_bool state;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &state_param);

	state = zephir_get_boolval(state_param);


	if (state) {
		zephir_update_property_zval(this_ptr, SL("returnAsTimestamp"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("returnAsTimestamp"), &__$false);
	}
	RETURN_THISW();

}

/**
 * sets the time of returned object
 * useful when post contains from -to
 * than you can set from 00:00:01 to 23.:59:59
 *
 * @param int|null $hours
 * @param int|null $minutes
 * @param int|null $seconds
 *
 * @return $this
 */
PHP_METHOD(Sanitizer_Sanitizers_Date, setTimeChange) {

	zval *hours_param = NULL, *minutes_param = NULL, *seconds_param = NULL, __$true, __$false, _0;
	zend_long hours, minutes, seconds;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 0, 3, &hours_param, &minutes_param, &seconds_param);

	if (!hours_param) {
		hours = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(hours_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hours' must be of the type int") TSRMLS_CC);
		RETURN_NULL();
	}
	hours = Z_LVAL_P(hours_param);
	}
	if (!minutes_param) {
		minutes = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(minutes_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'minutes' must be of the type int") TSRMLS_CC);
		RETURN_NULL();
	}
	minutes = Z_LVAL_P(minutes_param);
	}
	if (!seconds_param) {
		seconds = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(seconds_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'seconds' must be of the type int") TSRMLS_CC);
		RETURN_NULL();
	}
	seconds = Z_LVAL_P(seconds_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, hours);
	zephir_update_property_zval(this_ptr, SL("hour"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, minutes);
	zephir_update_property_zval(this_ptr, SL("minute"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, seconds);
	zephir_update_property_zval(this_ptr, SL("second"), &_0);
	if (1) {
		zephir_update_property_zval(this_ptr, SL("manualTime"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("manualTime"), &__$false);
	}
	RETURN_THISW();

}

/**
 * when returning a value, if it is valid
 * \DateTime object will be returned instead of formatted string date
 *
 * @param bool state
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Date, setReturnAsObject) {

	zval *state_param = NULL, __$true, __$false;
	zend_bool state;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &state_param);

	state = zephir_get_boolval(state_param);


	if (state) {
		zephir_update_property_zval(this_ptr, SL("returnAsObject"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("returnAsObject"), &__$false);
	}
	RETURN_THISW();

}

/**
 * @param string value
 *
 * @return \DateTime | null
 * @throws \Exception
 */
PHP_METHOD(Sanitizer_Sanitizers_Date, readDate) {

	zend_class_entry *_2$$4, *_5$$5;
	zend_bool _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, date, _0, _1, _8, _3$$4, _4$$4, _6$$5, _9$$6, _10$$6, _11$$6, _12$$6;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	if (UNEXPECTED(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(value_param) == IS_STRING)) {
		zephir_get_strval(&value, value_param);
	} else {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_EMPTY_STRING(&value);
	}


	zephir_read_property(&_0, this_ptr, SL("readFormat"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Read format must be specified", "sanitizer/Sanitizers/Date.zep", 158);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("timeZone"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_1) != IS_NULL) {
		_2$$4 = zephir_fetch_class_str_ex(SL("DateTime"), ZEND_FETCH_CLASS_AUTO);
		zephir_read_property(&_3$$4, this_ptr, SL("readFormat"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$4, this_ptr, SL("timeZone"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&date, _2$$4, "createfromformat", NULL, 0, &_3$$4, &value, &_4$$4);
		zephir_check_call_status();
	} else {
		_5$$5 = zephir_fetch_class_str_ex(SL("DateTime"), ZEND_FETCH_CLASS_AUTO);
		zephir_read_property(&_6$$5, this_ptr, SL("readFormat"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&date, _5$$5, "createfromformat", NULL, 0, &_6$$5, &value);
		zephir_check_call_status();
	}
	_7 = zephir_is_true(&date);
	if (_7) {
		zephir_read_property(&_8, this_ptr, SL("manualTime"), PH_NOISY_CC | PH_READONLY);
		_7 = ZEPHIR_IS_TRUE_IDENTICAL(&_8);
	}
	if (_7) {
		zephir_read_property(&_10$$6, this_ptr, SL("hour"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_11$$6, this_ptr, SL("minute"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_12$$6, this_ptr, SL("second"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_9$$6, &date, "settime", NULL, 0, &_10$$6, &_11$$6, &_12$$6);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&date, &_9$$6);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&date)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&date);

}

/**
 * @param \DateTimeZone zone
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Date, setTimeZone) {

	zval *zone, zone_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&zone_sub);

	zephir_fetch_params(0, 1, 0, &zone);



	zephir_update_property_zval(this_ptr, SL("timeZone"), zone);
	RETURN_THISW();

}

/**
 * @param string format
 * @param bool   setAsReturn
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Date, setReadFormat) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool setAsReturn;
	zval *format_param = NULL, *setAsReturn_param = NULL, _0$$3;
	zval format;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &format_param, &setAsReturn_param);

	if (UNEXPECTED(Z_TYPE_P(format_param) != IS_STRING && Z_TYPE_P(format_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'format' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(format_param) == IS_STRING)) {
		zephir_get_strval(&format, format_param);
	} else {
		ZEPHIR_INIT_VAR(&format);
		ZVAL_EMPTY_STRING(&format);
	}
	if (!setAsReturn_param) {
		setAsReturn = 0;
	} else {
		setAsReturn = zephir_get_boolval(setAsReturn_param);
	}


	zephir_update_property_zval(this_ptr, SL("readFormat"), &format);
	if (setAsReturn == 1) {
		ZVAL_BOOL(&_0$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setreturnformat", NULL, 0, &format, &_0$$3);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * @param string format
 * @param bool   setAsRead
 *
 * @return this
 */
PHP_METHOD(Sanitizer_Sanitizers_Date, setReturnFormat) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool setAsRead;
	zval *format_param = NULL, *setAsRead_param = NULL, _0$$3;
	zval format;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &format_param, &setAsRead_param);

	if (UNEXPECTED(Z_TYPE_P(format_param) != IS_STRING && Z_TYPE_P(format_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'format' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(format_param) == IS_STRING)) {
		zephir_get_strval(&format, format_param);
	} else {
		ZEPHIR_INIT_VAR(&format);
		ZVAL_EMPTY_STRING(&format);
	}
	if (!setAsRead_param) {
		setAsRead = 0;
	} else {
		setAsRead = zephir_get_boolval(setAsRead_param);
	}


	zephir_update_property_zval(this_ptr, SL("returnFormat"), &format);
	if (setAsRead == 1) {
		ZVAL_BOOL(&_0$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setreadformat", NULL, 0, &format, &_0$$3);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * returns default value for this object
 *
 * @return string|null
 */
PHP_METHOD(Sanitizer_Sanitizers_Date, getDefaultValue) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("nullAsDefault"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_NULL();
	}
	RETURN_STRING("");

}

