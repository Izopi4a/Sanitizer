
extern zend_class_entry *sanitizer_sanitizers_date_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Date);

PHP_METHOD(Sanitizer_Sanitizers_Date, getValue);
PHP_METHOD(Sanitizer_Sanitizers_Date, setReturnAsTimeStamp);
PHP_METHOD(Sanitizer_Sanitizers_Date, setTimeChange);
PHP_METHOD(Sanitizer_Sanitizers_Date, setReturnAsObject);
PHP_METHOD(Sanitizer_Sanitizers_Date, readDate);
PHP_METHOD(Sanitizer_Sanitizers_Date, setTimeZone);
PHP_METHOD(Sanitizer_Sanitizers_Date, setReadFormat);
PHP_METHOD(Sanitizer_Sanitizers_Date, setReturnFormat);
PHP_METHOD(Sanitizer_Sanitizers_Date, getDefaultValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_date_setreturnastimestamp, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, state, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, state)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_date_settimechange, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, hours, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, hours)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, minutes, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, minutes)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, seconds, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, seconds)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_date_setreturnasobject, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, state, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, state)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sanitizer_sanitizers_date_readdate, 0, 1, DateTime, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_date_readdate, 0, 1, IS_OBJECT, "DateTime", 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_date_settimezone, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, zone, DateTimeZone, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_date_setreadformat, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, format, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, format)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, setAsReturn, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, setAsReturn)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_date_setreturnformat, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, format, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, format)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, setAsRead, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, setAsRead)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_date_getdefaultvalue, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_date_getdefaultvalue, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizers_date_method_entry) {
	PHP_ME(Sanitizer_Sanitizers_Date, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Date, setReturnAsTimeStamp, arginfo_sanitizer_sanitizers_date_setreturnastimestamp, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Date, setTimeChange, arginfo_sanitizer_sanitizers_date_settimechange, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Date, setReturnAsObject, arginfo_sanitizer_sanitizers_date_setreturnasobject, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Date, readDate, arginfo_sanitizer_sanitizers_date_readdate, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Date, setTimeZone, arginfo_sanitizer_sanitizers_date_settimezone, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Date, setReadFormat, arginfo_sanitizer_sanitizers_date_setreadformat, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Date, setReturnFormat, arginfo_sanitizer_sanitizers_date_setreturnformat, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Date, getDefaultValue, arginfo_sanitizer_sanitizers_date_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
