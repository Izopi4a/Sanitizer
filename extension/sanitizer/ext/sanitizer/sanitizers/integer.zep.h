
extern zend_class_entry *sanitizer_sanitizers_integer_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Integer);

PHP_METHOD(Sanitizer_Sanitizers_Integer, getValue);
PHP_METHOD(Sanitizer_Sanitizers_Integer, checkMin);
PHP_METHOD(Sanitizer_Sanitizers_Integer, checkMax);
PHP_METHOD(Sanitizer_Sanitizers_Integer, setMinimum);
PHP_METHOD(Sanitizer_Sanitizers_Integer, setMaximum);
PHP_METHOD(Sanitizer_Sanitizers_Integer, getDefaultValue);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_integer_getvalue, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_integer_getvalue, 0, 0, IS_LONG, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_integer_checkmin, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_integer_checkmin, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_integer_checkmax, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_integer_checkmax, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_integer_setminimum, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_integer_setmaximum, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_integer_getdefaultvalue, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_integer_getdefaultvalue, 0, 0, IS_LONG, NULL, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizers_integer_method_entry) {
	PHP_ME(Sanitizer_Sanitizers_Integer, getValue, arginfo_sanitizer_sanitizers_integer_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Integer, checkMin, arginfo_sanitizer_sanitizers_integer_checkmin, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Integer, checkMax, arginfo_sanitizer_sanitizers_integer_checkmax, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Integer, setMinimum, arginfo_sanitizer_sanitizers_integer_setminimum, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Integer, setMaximum, arginfo_sanitizer_sanitizers_integer_setmaximum, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Integer, getDefaultValue, arginfo_sanitizer_sanitizers_integer_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
