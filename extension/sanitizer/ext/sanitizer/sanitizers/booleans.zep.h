
extern zend_class_entry *sanitizer_sanitizers_booleans_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Booleans);

PHP_METHOD(Sanitizer_Sanitizers_Booleans, getValue);
PHP_METHOD(Sanitizer_Sanitizers_Booleans, getDefaultValue);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_booleans_getvalue, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_booleans_getvalue, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_booleans_getdefaultvalue, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_booleans_getdefaultvalue, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizers_booleans_method_entry) {
	PHP_ME(Sanitizer_Sanitizers_Booleans, getValue, arginfo_sanitizer_sanitizers_booleans_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Booleans, getDefaultValue, arginfo_sanitizer_sanitizers_booleans_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
