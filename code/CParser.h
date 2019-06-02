#ifndef GRAPH_CPARSER_H
#define GRAPH_CPARSER_H


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include "CException.h"

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
private:
    /**
     * @name CParser#pcPARFields
     * @type {char **}
     * @desc The fields extracted from the file.
     * @private
     */
    char **pcPARFields;

    /**
     * @name CParser#uiPARNbFields
     * @type {unsigned int}
     * @desc The number of fields extracted from the file.
     * @private
     */
    unsigned int uiPARNbFields;

    /**
     * @name CParser#pcPARValues
     * @type {char ***}
     * @desc The values extracted from the file. Each value is an array of values.
     * @private
     */
    char ***pcPARValues;

    /**
     * @name CParser#uiPARNbValues
     * @type {unsigned int}
     * @desc The number of values extracted from the file. Should be equal to the number of fields.
     * @private
     */
    unsigned int uiPARNbValues;

    /**
     * @function CParser#extractValues
     * @param {const char*} pcFilePath - The path to the file.
     * @desc Does what it says. Fills this class's instance attributes.
     * @private
     */
    void extractValues(const char *pcFilePath);

protected:
    /**
     * @constructor
     * @param {const char*} pcFilePath
     * @desc Calls {@link CParser#extractValues}.
     */
    explicit CParser(const char *pcFilePath);

    /**
     * @desctructor
     */
    ~CParser();

    /**
     * @function CParser#PARGetFields
     * @return {const char**}
     * @desc {@link CParser#pcPARFields} getter.
     * <pre><code>{@link CParser} PARParser(const char* pcFilePath);
     * const char** ppcFields = PARParser.PARGetFields();
     * </code></pre>
     */
    const char **PARGetFields();

    /**
     * @function CParser#PARGetNbFields
     * @return {unsigned int}
     * @desc {@link CParser#uiPARNbFields} getter.
     * <pre><code>{@link CParser} PARParser(const char* pcFilePath);
     * unsigned int uiNbFields = PARParser.PARGetNbFields();
     * </code></pre>
     */
    unsigned int PARGetNbFields();

    /**
     * @function CParser#PARGetValues
     * @return {const char***}
     * @desc {@link CParser#pcPARValues} getter.
     * <pre><code>{@link CParser} PARParser(const char* pcFilePath);
     * const char*** pppcValues = PARParser.PARGetValues();
     * </code></pre>
     */
    const char ***PARGetValues();

    /**
     * @function CParser#PARGetNbValues
     * @return {unsigned int}
     * @desc {@link CParser#uiPARNbValues} getter.
     * <pre><code>{@link CParser} PARParser(const char* pcFilePath);
     * unsigned int uiNbValues = PARParser.PARGetNbValues();
     * </code></pre>
     */
    unsigned int PARGetNbValues();

    /**
     * @function CParser#PARGet
     * @param {const char*} pcField
     * @return {const char**}
     * @desc Returns a {@link CParser#pcPARValues} from a {@link CParser#pcPARFields}.
     * <pre><code>{@link CParser} PARParser(const char* pcFilePath);
     * const char** ppcValue = PARParser.PARGet("Field1");
     * </code></pre>
     */
    const char **PARGet(const char *pcField);

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
