# Izopi4a/Sanitizer

[![Build Status](https://travis-ci.com/Izopi4a/Sanitizer.svg?branch=master)](https://travis-ci.com/Izopi4a/Sanitizer)

Package to sanitize user inputs and ensuring data exists in arrays.

#### How to sanitize user's post / get

```php
    <?php
    
    use Sanitizer\Sanitizers\Emails;
    use Sanitizer\Sanitizers\Password;
    
    $sanitizer = new \Sanitizer\ArrayCaster($_POST);
    
    //give the sanitizer input name
    $sanitizer->add(new Emails("email"));
    $sanitizer->add(new Password("password"));
    $data = $sanitizer->getData();
    /*
    var_dump($data);
    array(24) {
      "email" => 
      string(0) ""
      'password' =>
      string(0) ""
    }
    
    $userClass->login($data['email'], $data['password']);
    */
```
#### Closure | shorten syntax usage

```php
<?php
    use Sanitizer\Sanitizers\Emails;
    use Sanitizer\Sanitizers\Password;
    
    $data = (new \Sanitizer\ArrayCaster($_POST, [
        (new Emails("email")),
        (new Password("password"))
    ]))->getData();

```

#### Available sanitizers

##### Integer
```php
<?php

use Sanitizer\Sanitizers\Integer;

$int = new Integer();
$int->setMaximum(5); // OPTIONAL sets maximum value
$int->setMaximum(1); // OPTIONAL sets minimum value 
$int->setNullAsDefault(true); // OPTIONAL will return null in case value is 0

```

##### Strings
```php
<?php

use Sanitizer\Sanitizers\Strings;

$strings = new Strings();
$strings->setMaxLength(5); // OPTIONAL sets maximum length of the string
$strings->setMinLength(1); // OPTIONAL sets minimum length of the string
$strings->setNullAsDefault(true); // OPTIONAL will return null in case value is empty string

```
##### Booleans
```php
<?php

use Sanitizer\Sanitizers\Booleans;

$bool = new Booleans();
// if input value is bool -> gets returned
// if input value is 1 ( ONLY 1) -> returns true
// if input value is 0 ( ONLY 0) -> returns false
// for everything else returns false   

```
##### Emails
```php
<?php

use Sanitizer\Sanitizers\Emails;

$email = new Emails();
$email->setNullAsDefault(true); // OPTIONAL will return null in case email is not valid

```
##### Floats
```php
<?php

use Sanitizer\Sanitizers\Floats;

$float = new Floats();
$float->setNullAsDefault(true); // OPTIONAL will return null in case value is 0
$float->setMaxDecimals(2); // OPTIONAL if set will round the value to that decimal point
$float->setMaximum(5); // OPTIONAL sets maximum value
$float->setMaximum(1); // OPTIONAL sets minimum value 

```
##### ArrayInteger
```php
<?php

use Sanitizer\Sanitizers\ArrayInteger;

$arrayInt = new ArrayInteger();
$arrayInt->setMaximum(5); // OPTIONAL sets maximum value of an value
$arrayInt->setMaximum(1); // OPTIONAL sets minimum value of an value
$arrayInt->setMaxItems(3); // OPTIONAL sets maximum amount of items

```

### Why ?

You should not rely on user's input. I am always amused by how many people work with their php warning off. PHP warning should always be on ( on dev env ofc).

If you are doing like so and someone calls your URL without parameters, this is what happens 

```php
$email =  $_POST['email'];
PHP Notice:  Undefined index: email in php shell code on line 11
```
and your code will do an mysql query to check for "such" user, even tho it's not really need to call the DB if user is empty.

so in normal way your code should look more or less something like this:

```php
if (true === isset($_POST['email'] && false === empty($_POST['email']) {
    return "error";
}
$email = $_POST['email'];
```

however if I post an `array` for email, what's gonna happen ? I don't know.. keep in mind strings are arrays of chars. So lets continue

```php
if (true === isset($_POST['email'] && false === empty($_POST['email'] && false === is_string($_POST['is_string']) {
    return "error";
}
$email = $_POST['email'];

if ($email === "" || false === filter_var($email, FILTER_VALIDATE_EMAIL)) {
    return "error";
}

```

i assume most of the cases this is fine, however It is a big pile of code that you need to copy/paste for every variable. That's why I created this library that should take care for most of user cases
