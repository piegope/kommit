/*
SPDX-FileCopyrightText: 2021 Hamed Masafi <hamed.masfi@gmail.com>

SPDX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include "solution.h"

namespace Diff
{
[[nodiscard]] Solution longestCommonSubsequence(const QStringList &source, const QStringList &target);

[[nodiscard]] Solution3 longestCommonSubsequence(const QStringList &source, const QStringList &target, const QStringList &target2);
}
