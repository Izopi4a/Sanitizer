
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Sanitizer_SizeInterface) {

	ZEPHIR_REGISTER_INTERFACE(Sanitizer, SizeInterface, sanitizer, sizeinterface, sanitizer_sizeinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Sanitizer_SizeInterface, setMinimum);

ZEPHIR_DOC_METHOD(Sanitizer_SizeInterface, setMaximum);

