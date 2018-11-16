<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\Strings;

    use PHPUnit\Framework\TestCase;

    final class StringsTest extends TestCase {

        protected $data = [];

        public function setUp() {

            $this->data = [
                "long"  => "asdasdasdfasdasdasdfasdasdasdf", //30
                "short" => "asd",
                "false" => false,
                "null"  => null,
                "array" => [],
                "arrayFilled" => [1 => 2, 3 => "asdasd"],
                "html" => "<br><span>a</span><div>b</div>",
                "quotes" => "a\"b'c%d\"e\\",
            ];
        }

        public function testMinLength(): void {

            $strings = new Strings();
            $strings->setRawValue($this->data['short']);
            $strings->setMinLength(5);

            $this->assertEquals($strings->getValue(), "", "Min string length is not working");

            $strings->setNullAsDefault(true);

            $this->assertNull($strings->getValue(), 'Min string length null is not working');
            $strings->setMinLength(0);

            $this->assertEquals($strings->getValue(), $this->data['short'], "string value changed for no reason");
        }

        public function testMaxLength(): void {

            $strings = new Strings();
            $strings->setRawValue($this->data['long']);
            $strings->setMaxLength(10);

            $this->assertEquals($strings->getValue(), "", "Max string length is not working");

            $strings->setNullAsDefault(true);

            $this->assertNull($strings->getValue(), 'Max string length null is not working');

            $strings->setMaxLength(30);

            $this->assertEquals($strings->getValue(), $this->data['long'], "string value changed for no reason");
        }

        public function testTrim() {

            $strings = new Strings();
            $strings->setRawValue("a ");

            $this->assertEquals($strings->getValue(), "a", "trim is not working");
        }

        public function testStripSlashes() {

            $strings = new Strings();
            $strings->setRawValue("\\a");

            $this->assertEquals($strings->getValue(), "a", "stripshases is not working");
        }

        public function testEscaping() {

            $strings = new Strings();
            $strings->setRawValue($this->data['quotes']);

            $this->assertEquals($strings->getValue(), "abc%de", "quotes trimming is not working");
        }

        public function testHtml() {

            $strings = new Strings();
            $strings->setRawValue($this->data['html']);

            $this->assertEquals($strings->getValue(), "ab", "html test is not working");
        }

        public function testNull() {

            $strings = new Strings();
            $strings->setRawValue($this->data['null']);

            $this->assertEquals($strings->getValue(), "");
        }

        public function testBool() {

            $strings = new Strings();
            $strings->setRawValue($this->data['false']);

            $this->assertEquals($strings->getValue(), "");
        }

        public function testArray() {

            $strings = new Strings();
            $strings->setRawValue($this->data['array']);

            $this->assertEquals($strings->getValue(), "");
        }

        public function testArrayFilled() {

            $strings = new Strings();
            $strings->setRawValue($this->data['arrayFilled']);

            $this->assertEquals($strings->getValue(), "");
        }

        public function testEmptyString() {

            $strings = new Strings();
            $strings->setRawValue("");

            $this->assertEquals($strings->getValue(), "");
        }

    }