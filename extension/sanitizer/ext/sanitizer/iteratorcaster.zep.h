
extern zend_class_entry *sanitizer_iteratorcaster_ce;

ZEPHIR_INIT_CLASS(Sanitizer_IteratorCaster);

PHP_METHOD(Sanitizer_IteratorCaster, __construct);
PHP_METHOD(Sanitizer_IteratorCaster, add);
PHP_METHOD(Sanitizer_IteratorCaster, getData);
zend_object *zephir_init_properties_Sanitizer_IteratorCaster(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_iteratorcaster___construct, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_iteratorcaster_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, sanitizer, Sanitizer\\SanitizerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_iteratorcaster_getdata, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_iteratorcaster_getdata, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_iteratorcaster_method_entry) {
	PHP_ME(Sanitizer_IteratorCaster, __construct, arginfo_sanitizer_iteratorcaster___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Sanitizer_IteratorCaster, add, arginfo_sanitizer_iteratorcaster_add, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_IteratorCaster, getData, arginfo_sanitizer_iteratorcaster_getdata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
