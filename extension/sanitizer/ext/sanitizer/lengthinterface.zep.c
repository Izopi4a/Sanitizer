
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Sanitizer_LengthInterface) {

	ZEPHIR_REGISTER_INTERFACE(Sanitizer, LengthInterface, sanitizer, lengthinterface, sanitizer_lengthinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Sanitizer_LengthInterface, setMinLength);

ZEPHIR_DOC_METHOD(Sanitizer_LengthInterface, setMaxLength);

