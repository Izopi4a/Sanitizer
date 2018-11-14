<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\Floats;

    use PHPUnit\Framework\TestCase;

    final class FloatsTest extends TestCase {

        /**
         * @param $value
         *
         * @return Floats
         */
        protected function getClass($value) {

            $b = new Floats();
            $b->setRawValue($value);

            return $b;
        }

        public function testString() : void {

            $floats = $this->getClass('asdasd');

            $this->assertEquals($floats->getValue(), 0.00);
            unset($floats);

            $floats = $this->getClass('1.11');

            $this->assertEquals($floats->getValue(), 1.11);
            unset($floats);

            $floats = $this->getClass('1,11');

            $this->assertEquals($floats->getValue(), 1.11);
            unset($floats);
        }

        public function testInt() : void {

            $floats = $this->getClass(0);

            $this->assertEquals($floats->getValue(), 0.00);
            unset($floats);

            $floats = $this->getClass(1);

            $this->assertEquals($floats->getValue(), 1.00);
            unset($floats);

            $floats = $this->getClass(2);

            $this->assertEquals($floats->getValue(), 2.00);
            unset($floats);
        }

        public function testUnchanged() : void {

            $floats = $this->getClass(1.11);

            $this->assertEquals($floats->getValue(), 1.11);
            unset($floats);

            $floats = $this->getClass(2.33);

            $this->assertEquals($floats->getValue(), 2.33);
            unset($floats);

            $floats = $this->getClass(4.56);

            $this->assertEquals($floats->getValue(), 4.56);
            unset($floats);
        }

        public function testNull() : void {

            $floats = $this->getClass(null);

            $this->assertEquals($floats->getValue(), 0.00);
        }

        public function testEmptyArray() : void {

            $floats = $this->getClass([]);

            $this->assertEquals($floats->getValue(), 0.00);
        }

        public function testArray() : void {

            $floats = $this->getClass(['a' => 1, 2 => 3]);

            $this->assertEquals($floats->getValue(), 0.00);
        }

    }