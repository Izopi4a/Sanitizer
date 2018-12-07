
extern zend_class_entry *sanitizer_sanitizer_ce;

ZEPHIR_INIT_CLASS(Sanitizer_Sanitizer);

PHP_METHOD(Sanitizer_Sanitizer, __construct);
PHP_METHOD(Sanitizer_Sanitizer, getVariableName);
PHP_METHOD(Sanitizer_Sanitizer, setNullAsDefault);
PHP_METHOD(Sanitizer_Sanitizer, setRawValue);
PHP_METHOD(Sanitizer_Sanitizer, getRawValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizer___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, variableName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, variableName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizer_getvariablename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sanitizer_sanitizer_getvariablename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizer_setnullasdefault, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, state, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, state)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sanitizer_setrawvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sanitizer_method_entry) {
	PHP_ME(Sanitizer_Sanitizer, __construct, arginfo_sanitizer_sanitizer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Sanitizer_Sanitizer, getVariableName, arginfo_sanitizer_sanitizer_getvariablename, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizer, setNullAsDefault, arginfo_sanitizer_sanitizer_setnullasdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizer, setRawValue, arginfo_sanitizer_sanitizer_setrawvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Sanitizer_Sanitizer, getRawValue, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
