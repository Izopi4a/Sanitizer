namespace Sanitizer;

interface SanitizerInterface {

    public function __construct(string variableName = null);

    public function getValue();

    public function getDefaultValue();

    public function getVariableName() -> string ;
}