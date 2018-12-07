
extern zend_class_entry *sanitizer_sanitizerinterface_ce;

ZEPHIR_INIT_CLASS(Sanitizer_SanitizerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizerinterface___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, variableName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, variableName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizerinterface_getvariablename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizerinterface_getvariablename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizerinterface_method_entry) {
	PHP_ABSTRACT_ME(Sanitizer_SanitizerInterface, __construct, arginfo_sanitizer_sanitizerinterface___construct)
	PHP_ABSTRACT_ME(Sanitizer_SanitizerInterface, getValue, NULL)
	PHP_ABSTRACT_ME(Sanitizer_SanitizerInterface, getDefaultValue, NULL)
	PHP_ABSTRACT_ME(Sanitizer_SanitizerInterface, getVariableName, arginfo_sanitizer_sanitizerinterface_getvariablename)
	PHP_FE_END
};
