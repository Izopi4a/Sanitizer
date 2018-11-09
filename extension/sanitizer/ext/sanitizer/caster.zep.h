
extern zend_class_entry *sanitizer_caster_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Caster);

PHP_METHOD(Sanitizer_Caster, __construct);
PHP_METHOD(Sanitizer_Caster, add);
PHP_METHOD(Sanitizer_Caster, getData);
zend_object *zephir_init_properties_Sanitizer_Caster(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_caster___construct, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_caster_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, sanitizer, Sanitizer\\SanitizerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_caster_getdata, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_caster_getdata, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_caster_method_entry) {
	PHP_ME(Sanitizer_Caster, __construct, arginfo_sanitizer_caster___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Sanitizer_Caster, add, arginfo_sanitizer_caster_add, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Caster, getData, arginfo_sanitizer_caster_getdata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
