/*
 * Copyright (C) 2015~2015 by CSSlayer
 * wengxt@gmail.com
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; see the file COPYING. If not,
 * see <http://www.gnu.org/licenses/>.
 */
#ifndef _FCITX_UTILS_I18NSTRING_H_
#define _FCITX_UTILS_I18NSTRING_H_

#include <unordered_map>
#include "fcitxutils_export.h"

namespace fcitx {
class FCITXUTILS_EXPORT I18NString {
public:
    I18NString() {}
    virtual ~I18NString() {}

    void set(std::string str, std::string locale = "") {
        if (locale.size()) {
            m_map[locale] = str;
        } else {
            m_default = str;
        }
    }

    void clear() {
        m_default.clear();
        m_map.clear();
    }

    const std::string &match(std::string locale);

protected:
    std::string m_default;
    std::unordered_map<std::string, std::string> m_map;
};
}

#endif // _FCITX_UTILS_I18NSTRING_H_