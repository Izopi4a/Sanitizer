
extern zend_class_entry *sanitizer_sanitizers_password_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Password);

PHP_METHOD(Sanitizer_Sanitizers_Password, getValue);
PHP_METHOD(Sanitizer_Sanitizers_Password, checkMinLength);
PHP_METHOD(Sanitizer_Sanitizers_Password, checkMaxLength);
PHP_METHOD(Sanitizer_Sanitizers_Password, setMinLength);
PHP_METHOD(Sanitizer_Sanitizers_Password, setMaxLength);
PHP_METHOD(Sanitizer_Sanitizers_Password, getDefaultValue);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_password_getvalue, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_password_getvalue, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_password_checkminlength, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_password_checkminlength, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_password_checkmaxlength, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_password_checkmaxlength, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_password_setminlength, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, min)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_password_setmaxlength, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, max)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_password_getdefaultvalue, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_password_getdefaultvalue, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizers_password_method_entry) {
	PHP_ME(Sanitizer_Sanitizers_Password, getValue, arginfo_sanitizer_sanitizers_password_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Password, checkMinLength, arginfo_sanitizer_sanitizers_password_checkminlength, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Password, checkMaxLength, arginfo_sanitizer_sanitizers_password_checkmaxlength, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Password, setMinLength, arginfo_sanitizer_sanitizers_password_setminlength, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Password, setMaxLength, arginfo_sanitizer_sanitizers_password_setmaxlength, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Password, getDefaultValue, arginfo_sanitizer_sanitizers_password_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
