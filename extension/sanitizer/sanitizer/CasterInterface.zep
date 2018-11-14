namespace Sanitizer;

interface CasterInterface {

    public function add(<SanitizerInterface> $sanitizer);

    public function getData() -> array;
}