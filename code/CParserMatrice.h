#ifndef MATRICEGAUSSJORDAN_CPARSERMATRICE_H
#define MATRICEGAUSSJORDAN_CPARSERMATRICE_H


#include <cstring>
#include <iostream>
#include <string>
#include "CParser.h"
#include "CMatrice.h"

/**
 * @class CParserMatrice
 * @extends CParser
 * @classdesc A class designed to create a {@link CMatrice} from a file.
 * <pre><code>{@link CParserMatrice} PMAParser(const char* pcFilePath);
 * </code></pre>
 */
class CParserMatrice : public CParser {
private:
    /**
     * @enum CParserGraphe#Fields
     * @desc Used to seek valid fields.
     * @private
     */
    enum Fields {
        TypeMatrice, NBLignes, NBColonnes, Matrice, INVALID
    };

    /**
     * @function CParserMatrice#PMAResolveField
     * @param {const char*} pcFieldString
     * @return {CParserMatrice#Fields}
     * @desc Returns a Field[enum] from a const char* supposedly describing a field.
     * @private
     */
    Fields PMAResolveField(const char *pcFieldString);

    /**
     * @name CParserGraphe#pGRAPGRGraphe
     * @type {CGraphe *}
     * @desc The resulting {@link CGraphe}. Retrive with {@link CParserGraphe#PGRGetGraph}().
     * @private
     */
    CMatrice<double> *pMATPMAMatrice;
public:

    /**
     * @constructor
     * @param {const char*} pcFilePath - The path to the file.
     * @desc Creates a new {@link CGraphe} from a file.
     * <pre><code>{@link CParserGraphe} PGRParserGraphe("test.txt");
     * PGRParserGraphe.{@link CParserGraphe#PGRGetGraph}().{@link CGraphe#GRAAfficherGraphe}();
     * </code></pre>
     */
    CParserMatrice(const char *pcFilePath);

    /**
     * @function CParserGraphe#PGRGetGraph
     * @return {CGraphe &}
     * @desc Returns (by reference) {@link CParserGraph#pGRAPGRGraphe}.
     * <pre><code>{@link CParserGraphe} PGRParserGraphe("test.txt");
     * PGRParserGraphe.{@link CParserGraphe}#PGRGetGraph().{@link CGraphe#GRAAfficherGraphe}();
     * </code></pre>
     */
    CMatrice<double> &PMAGetMatrice();
};


#endif //MATRICEGAUSSJORDAN_CPARSERMATRICE_H
