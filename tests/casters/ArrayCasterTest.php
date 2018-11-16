<?php
    declare(strict_types=1);

    use Sanitizer\ArrayCaster;

    use PHPUnit\Framework\TestCase;

    final class ArrayCasterTest extends TestCase {

        public function testNewClass() {

            $a = new ArrayCaster([]);

            $this->assertInstanceOf(ArrayCaster::class, $a);

        }

        public function testNewWithOptions() {

            $a = new ArrayCaster(['a' => 1], [
                new \Sanitizer\Sanitizers\Integer('a'),
                new \Sanitizer\Sanitizers\Integer('b'),
            ]);

            $data = $a->getData();

            $this->assertEquals($data['a'], 1);
            $this->assertEquals($data['b'], 0);
        }

        public function testNewWithoutOptions() {

            $a = new ArrayCaster(['a' => 1]);
            $a->add(new \Sanitizer\Sanitizers\Integer('a'));

            $data = $a->getData();

            $this->assertEquals($data['a'], 1);
        }
    }