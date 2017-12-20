/*
 * Copyright (C) 2016 Intel Corporation. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "test_va_api_fixture.h"

namespace VAAPI {

class VAAPIGetMaxValues
    : public VAAPIFixture
{
public:
    VAAPIGetMaxValues()
    {
        m_vaDisplay = doInitialize();
    }

    virtual ~VAAPIGetMaxValues()
    {
        doTerminate();
    }
};

TEST_F(VAAPIGetMaxValues, CheckMaxProfile)
{
    int profiles = 0;

    profiles = vaMaxNumProfiles(m_vaDisplay);
    EXPECT_TRUE(profiles > 0) << profiles
                              << " profiles are reported check setup";
}

TEST_F(VAAPIGetMaxValues, CheckMaxEntrypoints)
{
    int entryPoints = 0;

    entryPoints = vaMaxNumEntrypoints(m_vaDisplay);
    EXPECT_TRUE(entryPoints > 0) << entryPoints
                                 << " entrypoints are reported check setup";
}

TEST_F(VAAPIGetMaxValues, CheckMaxConfigAttributes)
{
    int configAttributes = 0;

    configAttributes = vaMaxNumConfigAttributes(m_vaDisplay);
    EXPECT_TRUE(configAttributes > 0)
        << configAttributes << " entrypoints are reported check setup";
}

} // VAAPI
