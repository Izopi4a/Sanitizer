<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\Integer;

    use PHPUnit\Framework\TestCase;

    final class IntegersTest extends TestCase {

        /**
         * @param $value
         *
         * @return Integer
         */
        protected function getClass($value) {

            $b = new Integer();
            $b->setRawValue($value);

            return $b;
        }

        public function testNullCast() :void {

            $integers = $this->getClass(null);

            $this->assertEquals(0, $integers->getValue());
        }

        public function testBoolCast() :void {

            $integers = $this->getClass(false);
            $this->assertEquals(0, $integers->getValue());
            unset($integers);

            $integers = $this->getClass(true);

            $this->assertEquals(0, $integers->getValue());
        }

        public function testStringCast() :void {

            $integers = $this->getClass("1");

            $this->assertEquals(1, $integers->getValue());
            unset($integers);

            $integers = $this->getClass("asd");

            $this->assertEquals(0, $integers->getValue());
        }

        public function testArrayCast() :void {

            $integers = $this->getClass([]);

            $this->assertEquals(0, $integers->getValue());
            unset($integers);

            $integers = $this->getClass([1 => 2, "c" => 'asda']);
            $this->assertEquals(0, $integers->getValue());
        }

        public function testRandomCast() :void {

            $integers = $this->getClass("\\");

            $this->assertEquals(0, $integers->getValue());
        }


        public function testZero() :void {

            $integers = $this->getClass(0);
            $integers->setNullAsDefault(true);

            $this->assertNull($integers->getValue());
        }

    }