
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Sanitizer_CasterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Sanitizer, CasterInterface, sanitizer, casterinterface, sanitizer_casterinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Sanitizer_CasterInterface, add);

ZEPHIR_DOC_METHOD(Sanitizer_CasterInterface, getData);

