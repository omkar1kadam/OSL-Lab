<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">

        <html>

        <head>
            <title>Student Result Report</title>

            <style>
                <!-- table {
                    border-collapse: collapse;
                    width: 60%;
                } -->

                th,
                td {
                    border: 1px solid black;
                    padding: 8px;
                    text-align: center;
                }

                th {
                    background-color: lightgray;
                }
            </style>

        </head>

        <body>

            <h2>Student Result Report</h2>

            <table>

                <tr>
                    <th>Name</th>
                    <th>Roll No</th>
                    <th>Marks</th>
                    <th>Result</th>
                </tr>

                <xsl:for-each select="students/student">

                    <tr>

                        <td>
                            <xsl:value-of select="name" />
                        </td>

                        <td>
                            <xsl:value-of select="rollno" />
                        </td>

                        <td>
                            <xsl:value-of select="marks" />
                        </td>

                        <td>

                            <xsl:choose>

                                <xsl:when test="marks &gt;= 40">
                                    Pass
                                </xsl:when>

                                <xsl:otherwise>
                                    Fail
                                </xsl:otherwise>

                            </xsl:choose>

                        </td>

                    </tr>

                </xsl:for-each>

            </table>

        </body>

        </html>

    </xsl:template>

</xsl:stylesheet>