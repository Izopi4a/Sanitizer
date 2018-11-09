<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\Integer;

    use PHPUnit\Framework\TestCase;

    final class IntegersTest extends TestCase {

        public function testNullCast() :void {

            $integers = new Integer(null);
            $integers->setRawValue(null);

            $this->assertEquals(0, $integers->getValue());
        }

        public function testBoolCast() :void {

            $integers = new Integer(null);
            $integers->setRawValue(false);

            $this->assertEquals(0, $integers->getValue());
            unset($integers);

            $integers = new Integer(null);
            $integers->setRawValue(true);

            $this->assertEquals(0, $integers->getValue());
        }

        public function testStringCast() :void {

            $integers = new Integer(null);
            $integers->setRawValue("1");

            $this->assertEquals(1, $integers->getValue());
            unset($integers);

            $integers = new Integer(null);
            $integers->setRawValue("asd");

            $this->assertEquals(0, $integers->getValue());
        }

        public function testArrayCast() :void {

            $integers = new Integer(null);
            $integers->setRawValue([]);

            $this->assertEquals(0, $integers->getValue());
            unset($integers);


            $integers = new Integer(null);
            $integers->setRawValue([1 => 2, "c" => 'asda']);

            $this->assertEquals(0, $integers->getValue());
        }

        public function testRandomCast() :void {

            $integers = new Integer(null);
            $integers->setRawValue("\\");

            $this->assertEquals(0, $integers->getValue());
        }

    }