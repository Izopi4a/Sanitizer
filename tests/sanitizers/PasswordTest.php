<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\Password;

    use PHPUnit\Framework\TestCase;

    final class PasswordTest extends TestCase {

        /**
         * @param $value
         *
         * @return Password
         */
        protected function getClass($value) {

            $a = new Password();
            $a->setRawValue($value);

            return $a;
        }

        public function testNormal() {

            $input = "abcdefghijklmnopqrst";
            $pass = $this->getClass($input);

            $this->assertEquals($input, $pass->getValue());
        }

        public function testSpecialChars() {

            $input = "a%\klmngu#^Sfgdfs!53321-1";
            $pass = $this->getClass($input);

            $this->assertEquals($input, $pass->getValue());
        }

        public function testNull() {

            $pass = $this->getClass(null);

            $this->assertEquals("", $pass->getValue());
        }

        public function testNullAsDefault() {

            $pass = $this->getClass(null);
            $pass->setNullAsDefault(true);

            $this->assertNull($pass->getValue());
        }

        public function testBool() {


            $pass = $this->getClass(true);
            $this->assertEquals("", $pass->getValue());
            unset($pass);

            $pass = $this->getClass(false);
            $this->assertEquals("", $pass->getValue());
        }

        public function testArray() {


            $pass = $this->getClass([]);
            $this->assertEquals("", $pass->getValue());
            unset($pass);
        }

        public function testFilledArray() {


            $pass = $this->getClass([1 => 'aaa', 'asdads' => 222]);
            $this->assertEquals("", $pass->getValue());
            unset($pass);
        }

        public function testAllBlankPassword() {


            $pass = $this->getClass("           ");
            $this->assertEquals("", $pass->getValue());
            unset($pass);
        }

        public function testMinLength() {


            $pass = $this->getClass("aaa");
            $pass->setMinLength(5);
            $this->assertEquals("", $pass->getValue());
        }

        public function testMaxLength() {


            $pass = $this->getClass("aaaaaaaaaaaaa");
            $pass->setMaxLength(5);
            $this->assertEquals("", $pass->getValue());
        }


    }