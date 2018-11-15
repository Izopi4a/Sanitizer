<?php
    declare(strict_types=1);

    use Sanitizer\IteratorCaster;

    use PHPUnit\Framework\TestCase;

    final class IteratorCasterTest extends TestCase {

        public function testNewClass() {

            $a = new IteratorCaster([]);

            $this->assertInstanceOf(IteratorCaster::class, $a);

        }

        public function testNewWithOptions() {

            $a = new IteratorCaster(['a' => 1], [
                new \Sanitizer\Sanitizers\Integer('a'),
                new \Sanitizer\Sanitizers\Integer('b'),
            ]);

            $data = $a->getData();

            $this->assertEquals($data['a'], 1);
            $this->assertEquals($data['b'], 0);
        }

        public function testNewWithoutOptions() {

            $a = new IteratorCaster(['a' => 1]);
            $a->add(new \Sanitizer\Sanitizers\Integer('a'));

            $data = $a->getData();

            $this->assertEquals($data['a'], 1);
        }

    }