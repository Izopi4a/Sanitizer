
extern zend_class_entry *sanitizer_sanitizers_emails_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Emails);

PHP_METHOD(Sanitizer_Sanitizers_Emails, getValue);
PHP_METHOD(Sanitizer_Sanitizers_Emails, getDefaultValue);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_emails_getvalue, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_emails_getvalue, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_emails_getdefaultvalue, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_emails_getdefaultvalue, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizers_emails_method_entry) {
	PHP_ME(Sanitizer_Sanitizers_Emails, getValue, arginfo_sanitizer_sanitizers_emails_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Emails, getDefaultValue, arginfo_sanitizer_sanitizers_emails_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
