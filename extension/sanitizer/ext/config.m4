PHP_ARG_ENABLE(sanitizer, whether to enable sanitizer, [ --enable-sanitizer   Enable Sanitizer])

if test "$PHP_SANITIZER" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, SANITIZER_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_SANITIZER, 1, [Whether you have Sanitizer])
	sanitizer_sources="sanitizer.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c sanitizer/sanitizer.zep.c
	sanitizer/sanitizerinterface.zep.c
	sanitizer/sizeinterface.zep.c
	sanitizer/casterinterface.zep.c
	sanitizer/lengthinterface.zep.c
	sanitizer/arraycaster.zep.c
	sanitizer/sanitizers/arrayinteger.zep.c
	sanitizer/sanitizers/booleans.zep.c
	sanitizer/sanitizers/emails.zep.c
	sanitizer/sanitizers/floats.zep.c
	sanitizer/sanitizers/integer.zep.c
	sanitizer/sanitizers/strings.zep.c "
	PHP_NEW_EXTENSION(sanitizer, $sanitizer_sources, $ext_shared,, )
	PHP_SUBST(SANITIZER_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([sanitizer], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([sanitizer], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/sanitizer], [php_SANITIZER.h])

fi
