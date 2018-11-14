
extern zend_class_entry *sanitizer_sizeinterface_ce;

ZEPHIR_INIT_CLASS(Sanitizer_SizeInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sizeinterface_setminimum, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sanitizer_sizeinterface_setmaximum, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sanitizer_sizeinterface_method_entry) {
	PHP_ABSTRACT_ME(Sanitizer_SizeInterface, setMinimum, arginfo_sanitizer_sizeinterface_setminimum)
	PHP_ABSTRACT_ME(Sanitizer_SizeInterface, setMaximum, arginfo_sanitizer_sizeinterface_setmaximum)
	PHP_FE_END
};
