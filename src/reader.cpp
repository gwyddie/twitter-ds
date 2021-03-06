//
// Created by Daniel Omiya on 09/05/21.
//

#include "reader.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
/* this file contains a lot of warnings but, as it is external,
 * there's no point in debbuging it
 */
#include "deps/csv.h"
#pragma GCC diagnostic pop

std::vector<Trend> getTrends(const std::string &path) {
  int volume;
  std::string name;
  std::vector<Trend> trends;
  io::CSVReader<2, io::trim_chars<' '>, io::no_quote_escape<';'>> in(path);

  in.read_header(io::ignore_extra_column, "name", "tweet_volume");
  while (in.read_row(name, volume)) {
    trends.emplace_back(Trend{name, volume});
  }

  return trends;
}
