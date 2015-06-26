#pragma once

#include "../initializator/initializators.hpp"

#include <map>

namespace znn { namespace v4 {

typedef std::vector<std::map<std::string, std::vector<cube_p<real>>>> inout_t;

template<typename Net>
inline std::pair<inout_t,inout_t> generate_inout( size_t n, Net const & net )
{
    auto ins  = net.inputs();
    auto outs = net.outputs();

    uniform_init init(1);
    std::pair<inout_t, inout_t> ret;

    for ( size_t i = 0; i < n; ++i )
    {
        std::map<std::string, std::vector<cube_p<real>>> insample;
        std::map<std::string, std::vector<cube_p<real>>> outsample;

        for ( auto & ip: ins )
        {
            for ( size_t i = 0; i < ip.second.second; ++i )
            {
                auto v = get_cube<real>(ip.second.first);
                init.initialize(*v);
                insample[ip.first].push_back(v);
            }
        }

        ret.first.push_back(insample);

        for ( auto & ip: outs )
        {
            for ( size_t i = 0; i < ip.second.second; ++i )
            {
                auto v = get_cube<real>(ip.second.first);
                init.initialize(*v);
                outsample[ip.first].push_back(v);
            }
        }

        ret.second.push_back(outsample);
    }
    return ret;
}


}} // namespace znn::v4
