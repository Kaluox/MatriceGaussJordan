#ifndef GRAPH_CPARSER_H
#define GRAPH_CPARSER_H

/**
 * @class CParser
 * @classdesc A generic parser for a file structured as:
 * <pre>example:
 * <code>field1 = value1
 * field2 = value2
 * ...
 * </code></pre>
 * To be noted: values can be written as arrays.
 * <pre><code>{@link CParser} PARParser(const char* pcFilePath);
 * </code></pre>
 */
class CParser {

protected:

    /**
     * @desctructor
     */
    ~CParser();

    /**
     * @function CParser#operator ()
     * @param {const char*} pcField
     * @return {const char**}
     * @desc Returns a {@link CParser#pcPARValues} from a {@link CParser#pcPARFields}.
     * <pre><code>{@link CParser} PARParser(const char* pcFilePath);
     * const char** ppcValue = PARParser("Field1");
     * </code></pre>
     */
    const char **operator()(const char *pcField);
};


#endif //GRAPH_CPARSER_H
