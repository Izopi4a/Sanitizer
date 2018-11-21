
extern zend_class_entry *sanitizer_sanitizers_arraystring_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_ArrayString);

PHP_METHOD(Sanitizer_Sanitizers_ArrayString, getValue);
PHP_METHOD(Sanitizer_Sanitizers_ArrayString, setMaxItems);
PHP_METHOD(Sanitizer_Sanitizers_ArrayString, setMinimum);
PHP_METHOD(Sanitizer_Sanitizers_ArrayString, setMaximum);
PHP_METHOD(Sanitizer_Sanitizers_ArrayString, getDefaultValue);
zend_object *zephir_init_properties_Sanitizer_Sanitizers_ArrayString(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_arraystring_getvalue, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_arraystring_getvalue, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_arraystring_setmaxitems, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, maxItems, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_arraystring_setminimum, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_arraystring_setmaximum, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_arraystring_getdefaultvalue, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_arraystring_getdefaultvalue, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizers_arraystring_method_entry) {
	PHP_ME(Sanitizer_Sanitizers_ArrayString, getValue, arginfo_sanitizer_sanitizers_arraystring_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_ArrayString, setMaxItems, arginfo_sanitizer_sanitizers_arraystring_setmaxitems, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_ArrayString, setMinimum, arginfo_sanitizer_sanitizers_arraystring_setminimum, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_ArrayString, setMaximum, arginfo_sanitizer_sanitizers_arraystring_setmaximum, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_ArrayString, getDefaultValue, arginfo_sanitizer_sanitizers_arraystring_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
