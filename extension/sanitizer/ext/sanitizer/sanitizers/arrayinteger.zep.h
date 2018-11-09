
extern zend_class_entry *sanitizer_sanitizers_arrayinteger_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_ArrayInteger);

PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, getValue);
PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, setMaxItems);
PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, setMinimum);
PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, setMaximum);
PHP_METHOD(Sanitizer_Sanitizers_ArrayInteger, getDefaultValue);
zend_object *zephir_init_properties_Sanitizer_Sanitizers_ArrayInteger(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_arrayinteger_getvalue, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_arrayinteger_getvalue, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_arrayinteger_setmaxitems, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, maxItems, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_arrayinteger_setminimum, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_arrayinteger_setmaximum, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_arrayinteger_getdefaultvalue, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_arrayinteger_getdefaultvalue, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizers_arrayinteger_method_entry) {
	PHP_ME(Sanitizer_Sanitizers_ArrayInteger, getValue, arginfo_sanitizer_sanitizers_arrayinteger_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_ArrayInteger, setMaxItems, arginfo_sanitizer_sanitizers_arrayinteger_setmaxitems, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_ArrayInteger, setMinimum, arginfo_sanitizer_sanitizers_arrayinteger_setminimum, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_ArrayInteger, setMaximum, arginfo_sanitizer_sanitizers_arrayinteger_setmaximum, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_ArrayInteger, getDefaultValue, arginfo_sanitizer_sanitizers_arrayinteger_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
