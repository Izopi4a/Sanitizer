
extern zend_class_entry *sanitizer_sanitizers_strings_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Strings);

PHP_METHOD(Sanitizer_Sanitizers_Strings, getValue);
PHP_METHOD(Sanitizer_Sanitizers_Strings, trim);
PHP_METHOD(Sanitizer_Sanitizers_Strings, checkMinLength);
PHP_METHOD(Sanitizer_Sanitizers_Strings, checkMaxLength);
PHP_METHOD(Sanitizer_Sanitizers_Strings, setMinLength);
PHP_METHOD(Sanitizer_Sanitizers_Strings, setMaxLength);
PHP_METHOD(Sanitizer_Sanitizers_Strings, getDefaultValue);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_getvalue, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_getvalue, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_trim, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_trim, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_checkminlength, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_checkminlength, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_checkmaxlength, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_checkmaxlength, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_strings_setminlength, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, min)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_strings_setmaxlength, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, max)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_getdefaultvalue, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_strings_getdefaultvalue, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizers_strings_method_entry) {
	PHP_ME(Sanitizer_Sanitizers_Strings, getValue, arginfo_sanitizer_sanitizers_strings_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Strings, trim, arginfo_sanitizer_sanitizers_strings_trim, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Strings, checkMinLength, arginfo_sanitizer_sanitizers_strings_checkminlength, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Strings, checkMaxLength, arginfo_sanitizer_sanitizers_strings_checkmaxlength, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Strings, setMinLength, arginfo_sanitizer_sanitizers_strings_setminlength, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Strings, setMaxLength, arginfo_sanitizer_sanitizers_strings_setmaxlength, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Strings, getDefaultValue, arginfo_sanitizer_sanitizers_strings_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
