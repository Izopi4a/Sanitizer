<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\Date;

    use PHPUnit\Framework\TestCase;

    final class DateTest extends TestCase {

        /**
         * @param $value
         *
         * @return Date
         */
        protected function getClass($value) {

            $b = new Date();
            $b->setRawValue($value);

            return $b;
        }

        public function testString() : void {

            $date = $this->getClass('asdasd');
            $date->setReadFormat("d-m-Y", true);

            $this->assertEquals("", $date->getValue());
        }

        public function testException() : void {

            $date = $this->getClass('asdasd');

            $this->expectException("\Exception");

            $date->getValue();
        }

        public function testWorking() : void {

            $date = $this->getClass('10-22-2018');
            $date->setReadFormat("m-d-Y", true);

            $this->assertEquals("10-22-2018", $date->getValue());
        }

        public function testTimestamp() : void {

            $date = $this->getClass('10-22-2018 00:00:00');
            $date->setReadFormat("m-d-Y H:i:s");
            $date->setReturnAsTimeStamp(true);
            $date->setTimeZone(new \DateTimeZone('UTC'));

            $this->assertEquals(1540166400, $date->getValue());
        }

        public function testBool() : void {

            $date = $this->getClass(true);
            $date->setReadFormat("m-d-Y");

            $this->assertEquals("", $date->getValue());
        }

        public function testReturnAsObject() : void {

            $date = $this->getClass("22-12-2016");
            $date->setReadFormat("d-m-Y");
            $date->setReturnAsObject(true);

            $this->assertInstanceOf('DateTime', $date->getValue());
        }

        public function testNullAsDefault() : void {

            $date = $this->getClass(false);
            $date->setReadFormat("d-m-Y");
            $date->setNullAsDefault(true);

            $this->assertNull($date->getValue());
        }

        public function testSetReturnFormatAsReadFormat() : void {

            $date = $this->getClass("22-02-2016");
            $date->setReturnFormat("d-m-Y", true);

            $this->assertEquals('22-02-2016', $date->getValue());
        }

        public function testTime() : void {

            $date = $this->getClass("22-02-2016");
            $date->setReadFormat("d-m-Y");
            $date->setReturnFormat("d-m-Y H:i:s");
            $date->setTimeChange(22, 0, 15);

            $this->assertEquals('22-02-2016 22:00:15', $date->getValue());
        }
    }
