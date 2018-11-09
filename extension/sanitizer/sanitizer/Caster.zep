namespace Sanitizer;

/**
 * class that helps you sanitize your user inputs
 *
 * Class Caster
 * @package Sanitizer
 */

class Caster {

    protected sanitizers = [];
    protected data = [];

    public function __construct(array! data, array items) {

        let this->data = data;

        if items !== null {
            var item;
            for item in items {
               this->add(item);
            }
        }
    }

    /**
     * adds sanitizer to the object
     * sanitizers are the one returning values from data source
     *
     * @param SanitizerInterface $sanitizer
     *
     * @return $this
     */

    public function add(<SanitizerInterface> sanitizer) {

        let this->sanitizers[] = sanitizer;

        return this;
    }

    /**
     * returns sanitized data
     *
     * @return array
     */
    public function getData() -> array {

        var data = [];

        var sanitizer;

        for sanitizer in this->sanitizers {

            var varName = sanitizer->getVariableName();

            if isset(this->data[varName]) === false {

                let data[varName] = sanitizer->getDefaultValue();
                continue;
            }

            sanitizer->setRawValue(this->data[$varName]);
            let data[varName] = sanitizer->getValue();
        }

        return data;
    }
}
