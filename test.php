<?php

    require_once __DIR__. '/vendor/autoload.php';

    use Sanitizer\Sanitizers\Integer;
    use Sanitizer\Sanitizers\Strings;
    use Sanitizer\Sanitizers\Booleans;
    use Sanitizer\Sanitizers\Emails;
    use Sanitizer\Sanitizers\ArrayInteger;
    use Sanitizer\Sanitizers\Floats;
    use Sanitizer\Sanitizers\ArrayString;

    $_POST['a'] = 2;
    $_POST['b'] = "asdssf11f";
    $_POST['c'] = "'false'";
    $_POST['d'] = "'true'";
    $_POST['e'] = "0";
    $_POST['f'] = "1";
    $_POST['g'] = "2";
    $_POST['h'] = true;
    $_POST['i'] = null;
    $_POST['l'] = false;
    $_POST['m'] = 'false';
    $_POST['aa'] = 'asfsadfsa@dfjsdf.com';
    $_POST['ab'] = 'fsdkfso@diasfdsdf.com';
    $_POST['ac'] = 'kfrokfeor@dirfdssd.com';
    $_POST['ba'] = '1,11';
    $_POST['bb'] = 2.22;
    $_POST['bc'] = '3.33';
    $_POST['ca'] = [1,2,3,4,5,6,7,8];
    $_POST['cb'] = [3,4,'bbdfbfd',false, null,'false'];
    $_POST['cc'] = '3.33';
    $_POST['ee'] = ['aaaa','bbbb', 'ccc'];

    $cls = new \Sanitizer\ArrayCaster($_POST, [
        (new Integer("a"))
            ->setMinimum(2)
            ->setMaximum(10)
            ->setNullAsDefault(true),
        (new Strings("b"))
            ->setMinLength(5)
            ->setMaxLength(10),
        new Booleans("e"),
        new Booleans("f"),
        new Emails("aa"),
        new Floats("bc"),
        (new ArrayInteger("ca"))->setMaximum(4),
        (new ArrayInteger("cb"))->setMaxItems(1),
        (new ArrayInteger("cc")),
        (new ArrayString("ee")),
    ]);

    echo PHP_EOL;
    echo " ----------- input ---------";
    echo PHP_EOL;
    var_dump($_POST);
    echo PHP_EOL;
    echo " ----------- output ---------";
    echo PHP_EOL;
    var_dump($cls->getData());