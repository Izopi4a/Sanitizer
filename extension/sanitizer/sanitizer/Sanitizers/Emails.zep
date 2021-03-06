namespace Sanitizer\Sanitizers;

use Sanitizer\Sanitizer;

class Emails extends Sanitizer {

    /** @var string  */
    protected val = "";

    /**
     * returns filtered value
     *
     * @return null|string
     */
    public function getValue() -> string | null {


        var strings;

        let strings = new Strings(null);

        strings->setRawValue(this->getRawValue());

        let this->val = strings->getValue();

        if (this->val === "") {
            return this->getDefaultValue();
        }

        if(!filter_var(this->val, FILTER_VALIDATE_EMAIL)){
            return this->getDefaultValue();
        }

        return this->val;
    }

    /**
     * returns default value for this object
     *
     * @return null|string
     */
    public function getDefaultValue() -> string | null {

        if (this->nullAsDefault) {
            return null;
        }

        return "";
    }
}
