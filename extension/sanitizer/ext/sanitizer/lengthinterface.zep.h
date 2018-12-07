
extern zend_class_entry *sanitizer_lengthinterface_ce;

ZEPHIR_INIT_CLASS(Sanitizer_LengthInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_lengthinterface_setminlength, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, min)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_lengthinterface_setmaxlength, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, max)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_lengthinterface_method_entry) {
	PHP_ABSTRACT_ME(Sanitizer_LengthInterface, setMinLength, arginfo_sanitizer_lengthinterface_setminlength)
	PHP_ABSTRACT_ME(Sanitizer_LengthInterface, setMaxLength, arginfo_sanitizer_lengthinterface_setmaxlength)
	PHP_FE_END
};
