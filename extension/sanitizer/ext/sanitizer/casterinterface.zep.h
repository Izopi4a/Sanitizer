
extern zend_class_entry *sanitizer_casterinterface_ce;

ZEPHIR_INIT_CLASS(Sanitizer_CasterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_casterinterface_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, sanitizer, Sanitizer\\SanitizerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_casterinterface_getdata, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_casterinterface_getdata, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_casterinterface_method_entry) {
	PHP_ABSTRACT_ME(Sanitizer_CasterInterface, add, arginfo_sanitizer_casterinterface_add)
	PHP_ABSTRACT_ME(Sanitizer_CasterInterface, getData, arginfo_sanitizer_casterinterface_getdata)
	PHP_FE_END
};
