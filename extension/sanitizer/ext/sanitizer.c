
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "sanitizer.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *sanitizer_sanitizerinterface_ce;
zend_class_entry *sanitizer_sizeinterface_ce;
zend_class_entry *sanitizer_casterinterface_ce;
zend_class_entry *sanitizer_lengthinterface_ce;
zend_class_entry *sanitizer_sanitizer_ce;
zend_class_entry *sanitizer_iteratorcaster_ce;
zend_class_entry *sanitizer_sanitizers_arrayinteger_ce;
zend_class_entry *sanitizer_sanitizers_booleans_ce;
zend_class_entry *sanitizer_sanitizers_emails_ce;
zend_class_entry *sanitizer_sanitizers_floats_ce;
zend_class_entry *sanitizer_sanitizers_integer_ce;
zend_class_entry *sanitizer_sanitizers_strings_ce;

ZEND_DECLARE_MODULE_GLOBALS(sanitizer)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(sanitizer)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Sanitizer_SanitizerInterface);
	ZEPHIR_INIT(Sanitizer_SizeInterface);
	ZEPHIR_INIT(Sanitizer_CasterInterface);
	ZEPHIR_INIT(Sanitizer_LengthInterface);
	ZEPHIR_INIT(Sanitizer_Sanitizer);
	ZEPHIR_INIT(Sanitizer_IteratorCaster);
	ZEPHIR_INIT(Sanitizer_Sanitizers_ArrayInteger);
	ZEPHIR_INIT(Sanitizer_Sanitizers_Booleans);
	ZEPHIR_INIT(Sanitizer_Sanitizers_Emails);
	ZEPHIR_INIT(Sanitizer_Sanitizers_Floats);
	ZEPHIR_INIT(Sanitizer_Sanitizers_Integer);
	ZEPHIR_INIT(Sanitizer_Sanitizers_Strings);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(sanitizer)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_sanitizer_globals *sanitizer_globals TSRMLS_DC)
{
	sanitizer_globals->initialized = 0;

	/* Memory options */
	sanitizer_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	sanitizer_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	sanitizer_globals->cache_enabled = 1;

	/* Recursive Lock */
	sanitizer_globals->recursive_lock = 0;

	/* Static cache */
	memset(sanitizer_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_sanitizer_globals *sanitizer_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(sanitizer)
{
	zend_sanitizer_globals *sanitizer_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	sanitizer_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(sanitizer_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(sanitizer_globals_ptr TSRMLS_CC);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(sanitizer)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(sanitizer)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SANITIZER_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SANITIZER_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SANITIZER_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SANITIZER_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SANITIZER_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(sanitizer)
{
	php_zephir_init_globals(sanitizer_globals TSRMLS_CC);
	php_zephir_init_module_globals(sanitizer_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(sanitizer)
{
	
}


zend_function_entry php_sanitizer_functions[] = {
	ZEND_FE_END

};

zend_module_entry sanitizer_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_SANITIZER_EXTNAME,
	php_sanitizer_functions,
	PHP_MINIT(sanitizer),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(sanitizer),
#else
	NULL,
#endif
	PHP_RINIT(sanitizer),
	PHP_RSHUTDOWN(sanitizer),
	PHP_MINFO(sanitizer),
	PHP_SANITIZER_VERSION,
	ZEND_MODULE_GLOBALS(sanitizer),
	PHP_GINIT(sanitizer),
	PHP_GSHUTDOWN(sanitizer),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(sanitizer),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SANITIZER
ZEND_GET_MODULE(sanitizer)
#endif
