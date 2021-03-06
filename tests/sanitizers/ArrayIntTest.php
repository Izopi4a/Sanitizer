<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\ArrayInteger;

    use PHPUnit\Framework\TestCase;

    final class ArrayIntTest extends TestCase {

        /**
         * @param $value
         *
         * @return ArrayInteger
         */
        protected function getClass($value) {

            $a = new ArrayInteger();
            $a->setRawValue($value);

            return $a;
        }

        public function testNormal() : void {

            $array = $this->getClass([1,2,3,4]);

            $this->assertEquals($array->getValue(), [1,2,3,4]);
        }

        public function testMaxItems() : void {

            $array = $this->getClass([1,2,3,4]);
            $array->setMaxItems(2);

            $this->assertEquals($array->getValue(), [1,2]);
        }

        public function testManyMaxItems() : void {

            $array = $this->getClass([1,2,3,4]);
            $array->setMaxItems(10);

            $this->assertEquals($array->getValue(), [1,2,3,4]);
        }

        public function testNull() : void {

            $array = $this->getClass(null);

            $this->assertEquals($array->getValue(), []);
        }

        public function testString() : void {

            $array = $this->getClass('aaaa');

            $this->assertEquals($array->getValue(), []);
            unset($array);

            $array = $this->getClass('[a => 1]');

            $this->assertEquals($array->getValue(), []);
        }

        public function testBool() : void {

            $array = $this->getClass(false);

            $this->assertEquals($array->getValue(), []);
            unset($array);

            $array = $this->getClass(true);
            $this->assertEquals($array->getValue(), []);
        }

        public function testMaxValue() : void {

            $array = $this->getClass([
                1,12,15
            ]);
            $array->setMaximum(10);
            $v = $array->getValue();

            $this->assertEquals(1, count($v));
            $this->assertEquals([1], $v);

        }

        public function testMinValue() : void {

            $array = $this->getClass([
                1,12,15
            ]);
            $array->setMinimum(10);
            $v = $array->getValue();

            $this->assertEquals(2, count($v));
            $this->assertEquals([12, 15], $v);

        }
    }