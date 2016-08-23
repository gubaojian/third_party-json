// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "catch.hpp"

#define private public
#include "json.hpp"

using nlohmann::json;

TEST_CASE("JS comments in JSON files")
{
    SECTION("single-line")
    {
      CHECK("{} // foo\n"_json == json({}));
      CHECK("[1, 2, // 3, \n 4]"_json == json({1,2,4}));
    }

    SECTION("multi-line")
    {
      CHECK("{} /* foo */"_json == json({}));
      CHECK("[1, 2, /* 3,  */ 4]"_json == json({1,2,4}));
    }
}
