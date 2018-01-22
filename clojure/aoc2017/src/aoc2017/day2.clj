(ns aoc2017.day2
  ( :require [clojure.string :as str]
             [clojure.math.combinatorics :as combo]
             [clojure.java.io :as io]))

(def test1 [[5 1 9 5]
            [7 5 3]
            [2 4 6 8]])

(defn spread
  [row]
  (- (apply max row) (apply min row)))

(reduce + (map spread test1))

(def test1str "5 1 9 5
              7 5 3
              2 4 6 8")

(defn split-whitespace [s]
  (str/split s #"\s+"))

(defn strings-to-ints [coll]
  (map #(Integer/parseInt %) coll))

(defn parse-int-table [s]
  (->> (str/split-lines s)
       (map str/trim)
       (map split-whitespace)
       (map strings-to-ints)))

(parse-int-table test1str)

(def puzzle-str (slurp "/home/grant/adventofcode2017/day2_input"))

(def puzzle-data (parse-int-table puzzle-str))

(def ans1 (reduce + (map spread puzzle-data)))

(println "First puzzle: " ans1)

(defn pairs
  [coll]
  (combo/combinations coll 2))

(pairs (first puzzle-data))

(defn evenly-divisible?
  [pair]
  (let [smaller (apply min pair)
        larger (apply max pair)]
    (= 0 (rem larger smaller))))

(defn row-division
  [row]
  (def p (first (filter evenly-divisible? (pairs row))))
  (let [smaller (apply min p)
        larger (apply max p)]
    (/ larger smaller)))

(def ans2 (apply + (map row-division puzzle-data)))

(println "Second puzzle: " ans2)
