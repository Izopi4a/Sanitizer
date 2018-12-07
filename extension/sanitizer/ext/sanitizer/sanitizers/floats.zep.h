
extern zend_class_entry *sanitizer_sanitizers_floats_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizers_Floats);

PHP_METHOD(Sanitizer_Sanitizers_Floats, getValue);
PHP_METHOD(Sanitizer_Sanitizers_Floats, setMaxDecimals);
PHP_METHOD(Sanitizer_Sanitizers_Floats, checkMin);
PHP_METHOD(Sanitizer_Sanitizers_Floats, checkMax);
PHP_METHOD(Sanitizer_Sanitizers_Floats, setMinimum);
PHP_METHOD(Sanitizer_Sanitizers_Floats, setMaximum);
PHP_METHOD(Sanitizer_Sanitizers_Floats, getDefaultValue);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_floats_getvalue, 0, 0, IS_DOUBLE, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_floats_getvalue, 0, 0, IS_DOUBLE, NULL, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_floats_setmaxdecimals, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, max)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_floats_checkmin, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_floats_checkmin, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_floats_checkmax, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_floats_checkmax, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_floats_setminimum, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, min)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizers_floats_setmaximum, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, max)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_floats_getdefaultvalue, 0, 0, IS_DOUBLE, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizers_floats_getdefaultvalue, 0, 0, IS_DOUBLE, NULL, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizers_floats_method_entry) {
	PHP_ME(Sanitizer_Sanitizers_Floats, getValue, arginfo_sanitizer_sanitizers_floats_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Floats, setMaxDecimals, arginfo_sanitizer_sanitizers_floats_setmaxdecimals, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Floats, checkMin, arginfo_sanitizer_sanitizers_floats_checkmin, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Floats, checkMax, arginfo_sanitizer_sanitizers_floats_checkmax, ZEND_ACC_PROTECTED)
	PHP_ME(Sanitizer_Sanitizers_Floats, setMinimum, arginfo_sanitizer_sanitizers_floats_setminimum, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Floats, setMaximum, arginfo_sanitizer_sanitizers_floats_setmaximum, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizers_Floats, getDefaultValue, arginfo_sanitizer_sanitizers_floats_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
