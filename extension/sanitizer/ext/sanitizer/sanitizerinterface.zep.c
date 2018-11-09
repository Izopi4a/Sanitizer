
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Sanitizer_SanitizerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Sanitizer, SanitizerInterface, sanitizer, sanitizerinterface, sanitizer_sanitizerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Sanitizer_SanitizerInterface, __construct);

ZEPHIR_DOC_METHOD(Sanitizer_SanitizerInterface, getValue);

ZEPHIR_DOC_METHOD(Sanitizer_SanitizerInterface, getDefaultValue);

ZEPHIR_DOC_METHOD(Sanitizer_SanitizerInterface, getVariableName);

